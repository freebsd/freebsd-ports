# New ports collection makefile for:	rpm
# Date created:		30 April 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rpm
PORTVERSION=	3.0.6
PORTREVISION=	9
CATEGORIES=	archivers
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-3.0.x/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Red Hat Package Manager

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
.if !exists(/usr/bin/bzip2)
LIB_DEPENDS+=	bz2.1:${PORTSDIR}/archivers/bzip2
.endif

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOMAKE_VER=14
USE_AUTOCONF_VER=213
USE_REINPLACE=	yes
USE_INC_LIBTOOL_VER=	13
CONFIGURE_ARGS=	--with-glob
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl -liconv"
INSTALLS_SHLIB=	yes
MAKE_ENV=	OLD_PO_FILE_INPUT=1

MAN1=		gendiff.1
MAN8=		rpm.8 rpm2cpio.8

post-patch:
.for file in rpm.c doc/rpm.8 lib/macro.c lib/rpmrc.c
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/${file}
.endfor

post-install:
		${INSTALL_MAN} ${WRKSRC}/doc/gendiff.1 ${PREFIX}/man/man1
		${INSTALL_MAN} ${WRKSRC}/doc/rpm.8 ${PREFIX}/man/man8
		${INSTALL_MAN} ${WRKSRC}/doc/rpm2cpio.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
