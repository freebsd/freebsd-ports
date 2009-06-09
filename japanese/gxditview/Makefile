# New ports collection makefile for:	gxditview (part of ja-groff)
# Date created:		14 April 1995
# Whom:			Nobuhiro Yasutomi <nobu@psrc.isac.co.jp>
#
# $FreeBSD$
#

PORTNAME=	gxditview
PORTVERSION=	1.18.1
DISTVERSIONSUFFIX=	.1
PORTREVISION=	7
CATEGORIES=	japanese print
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/g/groff
DISTNAME=	groff-${PORTVERSION}${DISTVERSIONSUFFIX}
DISTFILES=	${DISTNAME:S,-,_,}.orig${EXTRACT_SUFX}

PATCH_SITES=	${MASTER_SITE_DEBIAN}
PATCH_SITE_SUBDIR=	pool/main/g/groff
PATCHFILES=	${DISTNAME:S,-,_,}-12.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese enhancement of GNU xditview

RUN_DEPENDS=	${LOCALBASE}/bin/groff:${PORTSDIR}/japanese/groff

CONFLICTS=	gxditview-[1-9]*

GNU_CONFIGURE=	yes
USE_IMAKE=	yes
USE_XORG=	ice sm x11 xaw xext xmu xp xpm xt
USE_ICONV=	yes

CONFIGURE_ARGS=	--program-prefix=g --enable-multibyte
CONFIGURE_ENV=	INSTALL_MAN="${INSTALL_MAN}" \
		LIBS="-L${LOCALBASE}/lib -liconv"
CFLAGS+=	-I${LOCALBASE}/include

MAKE_ARGS=	GROFF_PREFIX=${LOCALBASE} \
		EXTRA_LIBRARIES="-L${LOCALBASE}/lib -liconv"
XDITVIEW_WRKSRC=${WRKDIR}/${DISTNAME}/src/xditview
BUILD_WRKSRC=	${XDITVIEW_WRKSRC}
INSTALL_WRKSRC=	${XDITVIEW_WRKSRC}

MAN1=		gxditview.1

.include <bsd.port.pre.mk>

post-extract:
	${CP} ${FILESDIR}/Imakefile ${WRKSRC}

post-patch:
	${REINPLACE_CMD} -e 's|^\(GROFF_PREFIX =\) @prefix@|\1 ${LOCALBASE}|g;' \
		${XDITVIEW_WRKSRC}/Imakefile.in
	${REINPLACE_CMD} -e 's|-I$$(TOOLKITSRC)|-I${LOCALBASE}/include|g;' \
		${XDITVIEW_WRKSRC}/Imakefile.in

post-configure:
	(cd ${XDITVIEW_WRKSRC}; ${SETENV} ${MAKE_ENV} ${XMKMF})

.include <bsd.port.post.mk>
