# New ports collection makefile for:   TrustedQSL
# Date created:                20th July 2004
# Whom:                        Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	trustedqsl
PORTVERSION=	1.13
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/${PORTNAME}/TrustedQSL/V1.13/
DISTFILES=	TrustedQSL-1.13.tar.gz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio Station electronic trusted logbook

LIB_DEPENDS=	tqsllib:${PORTSDIR}/comms/tqsllib

GNU_CONFIGURE=	yes
USE_WX=		2.8+
WX_UNICODE=	yes
CONFIGURE_ARGS=	--with-wxwindows=${WX_CONFIG}
USE_PERL5=	yes
USE_LDCONFIG=	yes
MAKE_ENV=	INCDIR="-I${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

WRKSRC=		${WRKDIR}/TrustedQSL-1.13

.include <bsd.port.pre.mk>

pre-configure:
	@${REINPLACE_CMD} -e 's|%%WX_CONFIG%%|${WX_CONFIG}|g' \
		 ${WRKSRC}/configure

post-install:
	@${ECHO_MSG}
	@${ECHO_MSG} trustedqsl is now installed. You will have to create a directory .tqsl in
	@${ECHO_MSG} your home directory and setup a copy of ${PREFIX}/share/tqsl/config.xml here
	@${ECHO_MSG} before this program will run correctly.
	@${ECHO_MSG}

.include <bsd.port.post.mk>
