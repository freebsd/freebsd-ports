# New ports collection makefile for:   libsigc++
# Date created:        27 January 2000
# Whom:                Joe Lu <JoeLu@JoeLu.m8.ntu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	libsigc++
PORTVERSION=	1.0.4
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:S/$/:gnome/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/1.0/:gnome \
		libsigc/:sf
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:sf,gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Callback Framework for C++

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_GNOME=	gnomehack

pre-configure:
	@${REINPLACE_CMD} -e 's#^sh libtool#${LIBTOOL}#' ${WRKSRC}/configure

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FEATURES ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/API ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/UML ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/conventions ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/diagrams ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/marshal ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/powerusers ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/requirements ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/riscos ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/signals ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/win32 ${DOCSDIR}
.endif

.include <bsd.port.mk>
