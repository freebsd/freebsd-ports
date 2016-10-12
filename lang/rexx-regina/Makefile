# Created by: ijliao
# $FreeBSD$

PORTNAME=	regina
PORTVERSION=	3.9.1
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}-rexx/${PORTNAME}-rexx/${PORTVERSION}:source \
		SF/${PORTNAME}-rexx/${PORTNAME}-documentation/${PORTVERSION}:docs
PKGNAMEPREFIX=	rexx-
DISTNAME=	Regina-REXX-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:source
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	Regina-REXX-${PORTVERSION}.tar.gz

MAINTAINER=	bob@eager.cx
COMMENT=	Rexx interpreter

LICENSE=	LGPL21+

BROKEN_aarch64=		Does not build: error: expected expression
BROKEN_armv6=		Does not build: error: expected expression
BROKEN_mips=		Does not build: error: expected expression
BROKEN_mips64=		Does not build: error: expected expression
BROKEN_powerpc64=	Does not build
BROKEN_sparc64=		Does not build: error: expected expression

USES=		gmake iconv ncurses
USE_RC_SUBR=	rxstack
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_c_char_unsigned=yes
CONFIGURE_ARGS=	--with-addon-dir=${PREFIX}/lib/Regina-REXX/addons
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX}${PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}

CONFLICTS=	rexx-imc-[0-0]* oorexx-[0-9]*

OPTIONS_DEFINE=	DOCS EXAMPLES
DOCS_DISTFILES=	regina.pdf:docs \
		regutil.pdf:docs

.include <bsd.port.options.mk>

.if ${ARCH} == i386 || ${ARCH} == powerpc
CONFIGURE_ARGS+=	--enable-32bit
.endif

post-extract-DOCS-on:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/regina.pdf ${WRKDIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/regutil.pdf ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e \
		'/$${CFLAGS}/s|^|#| ; \
		 s|"-lpthread"|"-pthread"|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^examplesdir/s|=.*|= $$(datadir)/examples/$$(PACKAGE)| ; \
		 /$$(sysconfdir)/s|^|#|' ${WRKSRC}/Makefile.in

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/regina.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKDIR}/regutil.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
