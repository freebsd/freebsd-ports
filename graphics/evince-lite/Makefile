# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PKGNAMESUFFIX=	-lite

COMMENT=	GNOME 3 multi-format document viewer without the GNOME dependancies

OPTIONS_EXCLUDE=	NAUTILUS

MASTERDIR=	${.CURDIR}/../../graphics/evince
SLAVEPORT=	lite
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

post-install:
	${RM} ${STAGEDIR}${PREFIX}/lib/systemd/user/evince.service
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/systemd/user
	${RMDIR} ${STAGEDIR}${PREFIX}/lib/systemd

.include "${MASTERDIR}/Makefile"
