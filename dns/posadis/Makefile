# New ports collection makefile for:	posadis
# Date Created:				27 Feb 2003
# Whom:					Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	posadis
PORTVERSION=	0.60.1
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sergei@kolobov.com
COMMENT=	"Domain Name Server (DNS) implementation"

LIB_DEPENDS=	poslib.0:${PORTSDIR}/devel/poslib

USE_LIBTOOL=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--disable-ltdl-install
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

MAN1=		getzone.1 posadis.1 posadis-getroots.1 posask.1 poshost.1
MAN5=		posadisrc.5
DOCS=		AUTHORS ChangeLog README TODO

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
