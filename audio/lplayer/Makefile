# ex:ts=8	-*-mode: makefile-*-
#
# New ports collection makefile for:	longplayer
# Date created:		2002-12-16
# Whom:			Alan Eldridge <alane@geeksrus.net>
#
# $FreeBSD$
#

PORTNAME=	lplayer
PORTVERSION=	1.01
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	sylvioc@gmail.com
COMMENT=	A QT program to queue lots of MP3s for random XMMS play

LIB_DEPENDS=	db_cxx-4.3.0:${PORTSDIR}/databases/db43 \
		xmms.4:${PORTSDIR}/multimedia/xmms

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_QT_VER=	3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-xmms-prefix=${X11BASE} --with-xinerama \
		--x-libraries=${X11BASE}/lib --x-includes=${X11BASE}/include
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOMAKE="${TRUE}" \
		AUTOHEADER="${TRUE}"

QTCPPFLAGS+=	-I${LOCALBASE}/include/db43

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 ||g ; \
		 s|-pedantic ||g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|-ldb_cxx|-ldb_cxx-4.3|g' ${WRKSRC}/configure

post-install:
	@${LN} -sf lplayer ${PREFIX}/bin/longplayer

.include <bsd.port.mk>
