# New ports collection makefile for:	grisbi
# Date created:		19 November 2002
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	grisbi
PORTVERSION=	0.6.0
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20${PORTVERSION}/${PORTVERSION}/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A personnal accounting application

LIB_DEPENDS=	ofx.4:${PORTSDIR}/finance/libofx	\
		ssl.7:${PORTSDIR}/security/openssl

USE_BZIP2=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 glib20 libxml2
INSTALLS_ICONS=	yes

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

pre-configure:
	${REINPLACE_CMD} -e "s|-lpthread|${PTHREAD_LIBS}|g"	\
		${WRKSRC}/${CONFIGURE_SCRIPT}
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e "s|pixmaps help|pixmaps|" ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
