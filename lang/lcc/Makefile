# ex:ts=8
# Ports collection makefile for:  lcc
# Date created:			  Sat Dec 7, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	lcc
PORTVERSION=	3.6
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.princeton.edu/pub/packages/lcc/

MAINTAINER=	obrien@FreeBSD.org
#origial [and extensive] patches by Soren Schmidt  / sos@freebsd.org

PLIST_SUB+=	ARCH=${ARCH}

MAKEFILE=	makefile
MAKE_FLAGS=	BUILDDIR=${LCCBUILDDIR} HOSTFILE=etc/${OPSYS}.c -f
MAN1=		bprint.1 lcc.1

UNAME_M!=	uname -m
LCCBUILDDIR=	${WRKDIR}/${UNAME_M}-${OPSYS}
LCCDESTDIR=	lib/${DISTNAME}/${UNAME_M}-${OPSYS}

pre-configure:
	@${MKDIR} ${LCCBUILDDIR}
	@${CP} ${FILESDIR}/${OPSYS}.md ${WRKSRC}/src
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g"  \
	     -e "s:%%LCCDESTDIR%%:${LCCDESTDIR}:g"  \
	     -e "s:%%VERSION%%:${DISTNAME}:g"  \
	     -e "s:!!ARCH!!:${ARCH}:g"  \
		${FILESDIR}/${OPSYS}.c.in > ${WRKSRC}/etc/${OPSYS}.c
	@#	below can be used to patchup PLIST file for diff os/arch
	@#${SED} -e "s:%%LCCDESTDIR%%:${LCCDESTDIR}:g"  \
		#${PKGDIR}/pkg-plist.in > ${PKGDIR}/pkg-plist
	@${SED} -e "s:%%OPSYS%%:${OPSYS}:g"  \
		${WRKSRC}/makefile > ${WRKSRC}/makefile.configured
	@${MV} -f ${WRKSRC}/makefile.configured ${WRKSRC}/makefile

do-install:
	@(umask 022 ; ${MKDIR} ${PREFIX}/${LCCDESTDIR})
	@${INSTALL_PROGRAM} ${LCCBUILDDIR}/lcc \
		${LCCBUILDDIR}/rcc \
		${LCCBUILDDIR}/cpp \
		${LCCBUILDDIR}/bprint \
		${LCCBUILDDIR}/bbexit.o \
		${PREFIX}/${LCCDESTDIR}
	@${LN} -sf ${PREFIX}/${LCCDESTDIR}/lcc ${PREFIX}/bin
	@${LN} -sf ${PREFIX}/${LCCDESTDIR}/bprint ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/doc/lcc.1 ${WRKSRC}/doc/bprint.1 \
		${PREFIX}/man/man1

.include <bsd.port.mk>
