#
# Makefile for today
#

CFLAGS += -DDISTRIBUTE -DMSG_STYLE
PROGRAM = today
MANPAGE = today.1
PREFIX = /usr/local
MANDIR = ${PREFIX}/man/ja/cat1
OBJSMV = birthday.o config.o date.o event.o getfile.o getsb.o \
	 history.o kansi.o kyureki.o kyusei.o list.o machine.o \
	 main.o misc.o pager.o rdcalendar.o schedule.o sekki.o sepparam.o
OBJS = $(OBJSMV) version.o
OBJS2 = calendar.o config.o getfile.o getsb.o kyureki2.o misc2.o \
	rdcalendar.o schedule2.o

all: ${PROGRAM} calendar-today dayinfo

install: ${PROGRAM} calendar-today dayinfo
	${INSTALL} -c -o bin -s ${PROGRAM} ${PREFIX}/bin
	${INSTALL} -c -o bin -s calendar-today ${PREFIX}/bin
	${INSTALL} -c -o bin -s dayinfo ${PREFIX}/bin
	mkdir -p ${MANDIR}
	cp today.doc ${MANPAGE}
	${INSTALL} -c -m 644 ${MANPAGE} ${MANDIR}
.if !defined(NOMANCOMPRESS)
	gzip -9nf ${MANDIR}/${MANPAGE}
.endif
	mkdir -p ${PREFIX}/lib
	${INSTALL} -c -m 644 -o bin today.cnf ${PREFIX}/lib
	mkdir -p ${PREFIX}/share/today
	${INSTALL} -c -m 644 -o bin *.tbl ${PREFIX}/share/today



today : $(OBJS)
	$(CC) $(OBJS) -lm -o $@

calendar-today : $(OBJS2)
	$(CC) $(OBJS2) -lm -o $@

dayinfo : dayinfo.c
	$(CC) $(CFLAGS) -lm $? -o $@

#inreki : inreki.c inreki.h
#	$(CC) $(CFLAGS) -DSTANDALONE $? -o $@
#kansi : kansi.c kansi.h
#	$(CC) $(CFLAGS) -DSTANDALONE -DDEBUG $? -o $@
#kyusei : kyusei.c kyusei.h
#	$(CC) $(CFLAGS) -DSTANDALONE $? -o $@

clean :
	rm -f *.o core calendar-today dayinfo inreki kansi kyusei today


birthday.o : birthday.c common.h main.h birthday.h getfile.h list.h misc.h \
	pager.h
calendar.o : calendar.c common.h config.h getfile.h getopt.h getsb.h \
	kyureki.h misc.h rdcalendar.h schedule.h
	$(CC) $(CFLAGS) -DINCLUDE_CALENDAR -c -o $@ calendar.c

config.o : config.c common.h config.h getfile.h
date.o : date.c common.h main.h date.h kansi.h kyusei.h misc.h pager.h \
	tide_tbl.c
event.o : event.c common.h main.h event.h getfile.h getsb.h kyureki.h list.h \
	misc.h pager.h sekki.h sepparam.h
getfile.o : getfile.c common.h getfile.h
getopt.o : getopt.c getopt.h
getsb.o : getsb.c getsb.h sb_tbl.c
history.o : history.c common.h main.h getfile.h history.h list.h misc.h pager.h
#inreki.o : inreki.c inreki.h
kansi.o : kansi.c kansi.h
kyureki.o : kyureki.c common.h main.h getfile.h kyureki.h misc.h kyutbl.c
kyureki2.o : kyureki.c common.h main.h getfile.h kyureki.h misc.h kyutbl.c
	$(CC) $(CFLAGS) -DINCLUDE_CALENDAR -c -o $@ kyureki.c

kyusei.o : kyusei.c kyusei.h
list.o : list.c list.h
machine.o : machine.c common.h machine.h main.h
main.o : main.c common.h main.h birthday.h config.h date.h event.h getfile.h \
	getopt.h history.h kyureki.h machine.h misc.h pager.h rdcalendar.h \
	schedule.h version.h
misc.o : misc.c common.h main.h getfile.h kyureki.h misc.h
misc2.o : misc.c common.h main.h getfile.h kyureki.h misc.h
	$(CC) $(CFLAGS) -DINCLUDE_CALENDAR -c -o $@ misc.c

pager.o : pager.c common.h main.h getfile.h misc.h pager.h
rdcalendar.o : rdcalendar.c common.h rdcalendar.h
schedule.o : schedule.c common.h main.h getfile.h list.h misc.h pager.h \
	schedule.h
schedule2.o : schedule.c common.h main.h getfile.h misc.h schedule.h
	$(CC) $(CFLAGS) -DINCLUDE_CALENDAR -c -o $@ schedule.c

sekki.o : sekki.c sekki.h
sepparam.o : sepparam.c sepparam.h
version.o : version.c version.h $(OBJSMV)
