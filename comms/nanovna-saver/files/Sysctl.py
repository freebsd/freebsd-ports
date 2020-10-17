import re
from ctypes import *
from ctypes.util import find_library

libc = cdll.LoadLibrary(find_library("c"))
sysctlbyname = libc.sysctlbyname

def posix_sysctlbyname(name):
    _len = c_uint(0)
    result = sysctlbyname(name,None , byref(_len), None, 0)
    _mem = create_string_buffer(_len.value)
    result = sysctlbyname(name, _mem, byref(_len), None, 0)
    if result != 0:
        raise Exception('sysctlbyname returned with error %s' % result)
    return _mem.value

def usb_vid_pid(name):
    digit = (re.search(r'\d',name)).group()
    result = (posix_sysctlbyname(b'dev.umodem.'+bytes(digit,'ascii')+b'.%pnpinfo')).decode('ascii')
    items=result.split(' ')
    vendor=int(items[0].split('=')[1],0)
    product=int(items[1].split('=')[1],0)
    return([vendor,product])
