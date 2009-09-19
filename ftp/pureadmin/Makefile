# ex:ts=8
# Ports collection makefile for:	pureadmin
# Date created:			Mar 4, 2005
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pureadmin
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	ftp
MASTER_SITES=	SF/purify/Default/${PORTVERSION}

MAINTAINER=	chris@officialunix.com
COMMENT=	Management utility for the PureFTPd

USE_GNOME=	pkgconfig gnomehack gnometarget libglade2
USE_FAM=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
INSTALLS_ICONS=	yes

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

PORTDOCS=	index.txt introduction.txt main_window.txt \
		preferences.txt user_manager.txt

pre-configure:
	@${REINPLACE_CMD} -e '/install-data-local:/s|install-docs||' ${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs/ && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
