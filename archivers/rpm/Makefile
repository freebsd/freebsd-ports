# New ports collection makefile for:	rpm
# Date created:		30 April 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rpm
PORTVERSION=	3.0.6
PORTREVISION=	14
CATEGORIES=	archivers
MASTER_SITES=	http://rpm5.org/files/rpm/rpm-3.0/ \
		http://ftp.tpnet.pl/vol/d4/ftp.rpm.org/rpm/dist/rpm-3.0.x/

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	The Red Hat Package Manager

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt

CONFLICTS=	rpm-4.* rpm-5.*

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	automake:14 autoconf:213 libtool:15
CONFIGURE_ARGS=	--with-glob
USE_LDCONFIG=	yes
MAKE_ENV=	OLD_PO_FILE_INPUT=1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl -liconv"
.endif

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
