# New ports collection makefile for:   libsigc++2
# Date created:        14 Feb 2004
# Whom:                Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/libsigc++20/Makefile,v 1.11 2008/03/10 15:08:22 ahze Exp $
#

PORTNAME=	libsigc++
PORTVERSION=	2.2.4
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++

BUILD_DEPENDS=	gm4:${PORTSDIR}/devel/m4

USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
LATEST_LINK=	libsigc++20
USE_LDCONFIG=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
GNU_CONFIGURE=	yes

PLIST_SUB=	VERSION="2.0" API_VERSION="2.0"

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|tests||; \
		/^SUBDIRS =/s|examples||" ${WRKSRC}/Makefile.in
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "/^install-data-am:/s/install-libsigc_docDATA//; \
		s/^\(SUBDIRS =\).*/\1/" \
		${WRKSRC}/docs/Makefile.in
.endif

.include <bsd.port.mk>
