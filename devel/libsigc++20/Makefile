# Created by: Alexander Nedotsukov <bland@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/devel/libsigc++20/Makefile 19952 2014-10-15 08:11:00Z gusi $

PORTNAME=	libsigc++
PORTVERSION=	2.4.1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool pathfix perl5 tar:xz
USE_PERL5=	build
USE_LDCONFIG=	yes

PLIST_SUB=	API_VERSION="2.0"

OPTIONS_DEFINE=	DOCS

DOCS_CONFIGURE_OFF=	--enable-documentation=no

post-patch:
	@${REINPLACE_CMD} -e "/^SUBDIRS =/s|tests||; \
		/^SUBDIRS =/s|examples||" ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
