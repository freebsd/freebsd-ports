# New ports collection makefile for:    elvis + japanese patch
# Date created:         5 October 1995
# Whom:                 Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	elvis
PORTVERSION=	1.8.4
PORTREVISION=	1
CATEGORIES=	japanese editors
MASTER_SITES=	ftp://ftp.cs.pdx.edu/pub/elvis/
EXTRACT_SUFX=	.tgz
DISTNAME=	${PORTNAME}-1.8

PATCH_SITES=	ftp://ftp.foretune.co.jp/pub/tools/jelvis/
PATCHFILES=	j${PORTNAME}1.8p4-j1.1.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A clone of vi/ex, the standard UNIX editor, with Japanese patch

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna

NO_WRKSUBDIR=	yes
PATCH_DIST_STRIP=	-p1
MAN1=		elvis.1 ctags.1 ref.1 elvrec.1 elvprsv.1

STARTUP_SCRIPT=	${PREFIX}/etc/rc.d/ja-elvis.sh

do-configure:
	@${CP} ${WRKSRC}/Makefile.mix ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${PREFIX}/share/doc/ja-elvis
	${INSTALL_DATA} ${WRKSRC}/README.j18 ${PREFIX}/share/doc/ja-elvis
	@${SH} ${PKGREQ} ${PKGNAME} INSTALL
	@if [ ! -f ${STARTUP_SCRIPT} ]; then				\
		${ECHO_MSG} "Installing ${STARTUP_SCRIPT} startup file.";	\
		${INSTALL_SCRIPT} ${FILESDIR}/ja-elvis.sh ${STARTUP_SCRIPT};\
	fi

.include <bsd.port.mk>
