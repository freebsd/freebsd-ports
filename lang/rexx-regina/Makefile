# Created by: ijliao
# $FreeBSD$

PORTNAME=	regina
PORTVERSION=	3.8
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}-rexx/${PORTNAME}-rexx/${PORTVERSION}
PKGNAMEPREFIX=	rexx-
DISTNAME=	Regina-REXX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rexx interpreter

LICENSE=	LGPL21 # (or later)

USES=		gmake iconv
USE_RC_SUBR=	rxstack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_c_char_unsigned=yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

DATADIR=	${PREFIX}/share/Regina-REXX

CONFLICTS=	rexx-imc-[0-0]* oorexx-[0-9]*

BROKEN_powerpc=	Does not link on powerpc

.include <bsd.port.options.mk>

.if ${ARCH} == i386
CONFIGURE_ARGS+=	--enable-32bit
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/$${CFLAGS}/s|^|#| ; \
		 s|"-lpthread"|"-pthread"|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/$$(sysconfdir)/s|^|#|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
