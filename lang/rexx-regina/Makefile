# Created by: ijliao
# $FreeBSD$

PORTNAME=	regina
PORTVERSION=	3.8.2
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}-rexx/${PORTNAME}-rexx/${PORTVERSION}
PKGNAMEPREFIX=	rexx-
DISTNAME=	Regina-REXX-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Rexx interpreter

LICENSE=	LGPL21+

BROKEN_powerpc64=	Does not build

USES=		gmake iconv tar:bzip2
USE_RC_SUBR=	rxstack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_c_char_unsigned=yes
CONFIGURE_ARGS=	--with-addon-dir=${PREFIX}/lib/Regina-REXX/addons
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

DATADIR=	${PREFIX}/share/Regina-REXX
EXAMPLESDIR=	${PREFIX}/share/examples/Regina-REXX

CONFLICTS=	rexx-imc-[0-0]* oorexx-[0-9]*

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>

.if ${ARCH} == i386 || ${ARCH} == powerpc
CONFIGURE_ARGS+=	--enable-32bit
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/$${CFLAGS}/s|^|#| ; \
		 s|"-lpthread"|"-pthread"|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^examplesdir/s|=.*|= $$(datadir)/examples/$$(PACKAGE)| ; \
		 /$$(sysconfdir)/s|^|#|' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
