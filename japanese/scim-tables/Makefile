# New ports collection makefile for:    ja-scim-tables
# Date created:		22 May 2004
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#

PORTNAME=	scim-tables
PORTVERSION=	0.5.7
PORTREVISION=	3
CATEGORIES=	japanese
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	SCIM table based Japanese input methods

BUILD_DEPENDS=	scim-make-table:${PORTSDIR}/textproc/scim-table-imengine
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl" \
		SCIM_DATADIR=${PREFIX}/share/scim \
		SCIM_ICONDIR=${PREFIX}/share/scim/icons

CONFIGURE_ARGS+=	--disable-skim-support

post-extract:
	@${CP} ${FILESDIR}/T-Code.txt.in   ${WRKSRC}/tables/ja/
	@${CP} ${FILESDIR}/TUT-Code.txt.in ${WRKSRC}/tables/ja/

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.post.mk>
