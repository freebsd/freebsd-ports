# New ports collection makefile for:	qhacc
# Date created:		28 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	qhacc
PORTVERSION=	1.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.ostrich-emulators.cx/qhacc/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

USE_QT_VER=	2
USE_X_PREFIX=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-moc=${X11BASE}/bin \
		--with-qt-libs=${X11BASE}/lib

post-extract:
	@${RM} -f ${WRKSRC}/src/moc_*.cpp

pre-patch:
.for file in configure src/Makefile.in
	@${PERL} -pi -e 's|/moc|/${MOC:T}|g ; \
		 s|-lqt|-l${QTNAME}|g ; \
		 s|-O2 -Wall|\@CXXFLAGS\@|g' ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/qhacc ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/config ${DATADIR}/config.sample
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DOCSDIR}
.endif
	@${SED} -e "s:/usr/X11R6:${PREFIX}:g" ${PKGMESSAGE}

.include <bsd.port.mk>
