
AM_DEVELOP= -O2 -DDEBUG -g -DAMULET2_CONVERSION
AM_RELEASE= -O2 -DAMULET2_CONVERSION
AM_NODEBUGSYM= -O2 -DDEBUG -DAMULET2_CONVERSION

## The default build has two parameters: OP and LIB_MODIFIER
## used to specify the variant of the Amulet library that will be used
## OP chooses one of the sets of compiler flags:
## AM_DEVELOP, AM_RELEASE, AM_INHOUSE, AM_NODEBUGSYM
OP=$(AM_DEVELOP)

## LIB_MODIFIER is appended to library filename to indicate particular
## OP choice: blank for AM_DEVELOP, -release for AM_RELEASE
LIB_MODIFIER=

## To link with the release library, invoke make as follows
##	Make OP='$(AM_RELEASE)' LIB_MODIFIER=-release

CFLAGS+= -I$(X11BASE)/include -DGCC -DMEMORY
LDFLAGS+= -lamulet$(LIB_MODIFIER) -lstdc++ -lg++ \
        -L$(X11BASE)/lib -lX11 -lm

PROG= xxxx
SRCS= xxxx.cc

xxxx: xxxx.o 
	$(CC) -o xxxx $(.ALLSRC) $(LDFLAGS) 

xxxx.o: xxxx.cc
	$(CXX) -c $(CXXFLAGS) $(OP) $(.IMPSRC)
clean:
	-rm -f *.o xxxx
