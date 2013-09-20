# Created by: Diane Bruce <db@db.net>
# $FreeBSD$

PORTNAME=	flwrap
PORTVERSION=	1.3.4
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/downloads/flwrap/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Flwrap is a companion utility for fldigi

LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_DOS2UNIX=	yes
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"

NO_STAGE=	yes
post-configure:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|^CPPFLAGS|#CPPFLAGS|' \
		${WRKSRC}/src/Makefile

post-install:
.if	!defined(NOPORTDOCS)
	@${ECHO} ""
	@${MKDIR} ${DOCSDIR}
	@@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${ECHO} "flwrap docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.mk>
