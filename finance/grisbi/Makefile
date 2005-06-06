# New ports collection makefile for:	grisbi
# Date created:		19 November 2002
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	grisbi
PORTVERSION=	0.5.7
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A personnal accounting application

LIB_DEPENDS=	ofx.1:${PORTSDIR}/finance/libofx
.if !defined(WITHOUT_LATEX)
RUN_DEPENDS=	${UCS_CLASSDIR}/ucs.sty:${PORTSDIR}/print/latex-ucs
.endif

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GCC=	3.4
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 glib20 libxml2

TEXMF?=		share/texmf-local
UCS_CLASSDIR=	${LOCALBASE}/${TEXMF}/tex/latex/ucs

MAN1=		grisbi.1

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}"	\
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(NOPORTDOCS)
USE_REINPLACE=	yes
.endif

pre-configure:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e "s|pixmaps help|pixmaps|" ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
