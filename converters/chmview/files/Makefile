#
# $FreeBSD$
#
OBJDIR = .
EXEDIR = .
EXENAME = $(EXEDIR)/chmview

CFLAGS += -g
LFLAGS += -g

all: $(EXENAME)

OBJS = $(OBJDIR)/chmview.o \
       $(OBJDIR)/chmlib.o \
       $(OBJDIR)/lzx.o

$(OBJDIR)/chmview.o: chmview.c chmlib.h
$(OBJDIR)/chmlib.o: chmlib.c chmlib.h fixendian.h lzx.h
$(OBJDIR)/lzx.o: lzx.c lzx.h lzx_int.h

.c.o:
	$(CC) $(CFLAGS) -c ${.IMPSRC}

$(EXENAME): $(OBJS)
	echo $(OBJS)
	$(CC) $(LFLAGS) -o $(EXENAME) ${.ALLSRC}
