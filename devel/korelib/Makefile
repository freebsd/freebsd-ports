# New ports collection makefile for:	korelib
# Date created:				10 May 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	korelib
PORTVERSION=	0.0.1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.thekompany.com/Korelib/releases/

MAINTAINER=	ports@FreeBSD.org

USE_KDELIBS_VER=2
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

pre-configure:
	${PERL} -pi -e "s@-g -O2@${CFLAGS}@g; s@-O2@${CFLAGS}@g" \
		${WRKSRC}/configure ${WRKSRC}/*/Makefile.in ${WRKSRC}/*/*/Makefile.in

.include <bsd.port.mk>
