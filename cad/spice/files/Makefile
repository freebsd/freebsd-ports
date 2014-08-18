#
# $FreeBSD$
#

.ifdef WITHOUT_X11
CONFIG=	FreeBSD.without_x11
.else
CONFIG=	FreeBSD
.endif

all:
	util/build ${CONFIG} default

install:
	mkdir -p ${DESTDIR}${PREFIX}/share/spice/helpdir \
		${DESTDIR}${PREFIX}/share/spice/scripts
	(cd ${CONFIG}/obj/bin && ${BSD_INSTALL_PROGRAM} \
		spice3 nutmeg sconvert help proc2mod multidec \
		${DESTDIR}${PREFIX}/bin)
	${BSD_INSTALL_DATA} lib/helpdir/spice.txt \
		${DESTDIR}${PREFIX}/share/spice/helpdir
	${BSD_INSTALL_SCRIPT} lib/scripts/setplot lib/scripts/spinit \
		${DESTDIR}${PREFIX}/share/spice/scripts
	${BSD_INSTALL_DATA} lib/mfbcap lib/news \
		${DESTDIR}${PREFIX}/share/spice
	${BSD_INSTALL_MAN} man/man5/mfbcap.5 \
		${DESTDIR}${PREFIX}/man/man5/mfbcap.5
	${BSD_INSTALL_MAN} man/man1/sconvert.1 \
		${DESTDIR}${PREFIX}/man/man1/sconvert.1
	${BSD_INSTALL_MAN} man/man1/nutmeg.1 \
		${DESTDIR}${PREFIX}/man/man1/nutmeg.1
	${BSD_INSTALL_MAN} man/man1/spice.1 \
		${DESTDIR}${PREFIX}/man/man1/spice.1
	${BSD_INSTALL_MAN} man/man1/spice.1 \
		${DESTDIR}${PREFIX}/man/man1/spice3.1
	${BSD_INSTALL_MAN} man/man3/mfb.3 \
		${DESTDIR}${PREFIX}/man/man3/mfb.3
