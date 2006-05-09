# New ports collection makefile for:	ooRexx
# Date created:				04 Jun 2005
# Whom:					Micho
#
# $FreeBSD$
#

PORTNAME=	oorexx
PORTVERSION=	3.0.0
CATEGORIES=	lang
MASTER_SITES=	http://www.matem.unam.mx/~micho/download/

MAINTAINER=	micho@matem.unam.mx
COMMENT=	A powerful typeless object-oriented scripting language

CONFLICTS=	rexx-imc-[0-9]* rexx-regina-[0-9]*

INSTALLS_SHLIB=	yes
MAKE_ENV=	EXAMPLESDIR="${EXAMPLESDIR}"
MAN1=		rexx.1 rexxc.1 rxmigrate.1 rxsubcom.1 rxqueue.1

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-D_REENTRANT|${PTHREAD_CFLAGS}|; \
		s|-pthread|${PTHREAD_LIBS}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's|/usr/local/oorexx|${PREFIX}/lib/oorexx|' \
		${WRKSRC}/rxtests/README

.include <bsd.port.post.mk>
