import forklib
import logging
import os
from time import sleep


logging.basicConfig(level=logging.DEBUG)

def run():
    print(
        "Proceess #{id} has PID: {pid}".format(
            id=forklib.get_id(),
            pid=os.getpid()
        )
    )
    sleep(1)

def main():
    print("Master proccess has PID: {0}".format(os.getpid()))
    forklib.fork(100, run)

if __name__ == '__main__':
    main()
