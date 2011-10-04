# New ports collection makefile for:    ldb
# Date created:         Sep 6 2011
# Whom:                 Ryan Steinmetz <zi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ldb
DISTVERSION=	1.1.0
CATEGORIES=	databases
MASTER_SITES=	SAMBA
MASTER_SITE_SUBDIR=	../../ftp/pub/${PORTNAME}

MAINTAINER=	aweits@rit.edu
COMMENT=	An LDAP-like embedded database

LICENSE=	LGPL3

LIB_DEPENDS=	talloc.2:${PORTSDIR}/devel/talloc \
		tevent.0:${PORTSDIR}/devel/tevent \
		tdb.1:${PORTSDIR}/databases/tdb \
		popt.0:${PORTSDIR}/devel/popt \
		xslt.2:${PORTSDIR}/textproc/libxslt

CONFLICTS=	samba4-devel-4*

CONFIGURE_ARGS=	--with-modulesdir=${PREFIX}/lib \
		--builtin-libraries="tdb replace" \
		--bundled-libraries=NONE
CFLAGS+=	-L${LOCALBASE}/lib

HAS_CONFIGURE=	yes
USE_PYTHON=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|..LIBDIR}/pkgconfig|${PREFIX}/libdata/pkgconfig|g' ${WRKSRC}/wscript

.include <bsd.port.mk>
