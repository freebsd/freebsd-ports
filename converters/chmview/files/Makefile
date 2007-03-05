#
# $FreeBSD$
#
OBJDIR = .
EXEDIR = .
EXENAME = $(EXEDIR)/chmview

CFLAGS += -DUNIX

all: $(EXENAME)

OBJS = $(OBJDIR)/chmview.o \
       $(OBJDIR)/chm_lib.o \
       $(OBJDIR)/lzx.o \
       $(OBJDIR)/utf8.o

$(OBJDIR)/chmview.o: chmview.c chm_lib.h
$(OBJDIR)/chm_lib.o: chm_lib.c chm_lib.h lzx.h
$(OBJDIR)/utf8.o: utf8.c utf8.h
$(OBJDIR)/lzx.o: lzx.c lzx.h

.c.o:
	$(CC) $(CFLAGS) -c ${.IMPSRC}

$(EXENAME): $(OBJS)
	echo $(OBJS)
	$(CC) $(LFLAGS) -o $(EXENAME) ${.ALLSRC}
