# Created by: ijliao
# $FreeBSD$

PORTNAME=	regina
PORTVERSION=	3.9.1
PORTREVISION=	1
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

post-extract-DOCS-on:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/regina.pdf ${WRKDIR}
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/regutil.pdf ${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e \
		'/^examplesdir/s|=.*|= $$(datadir)/examples/$$(PACKAGE)| ; \
		 /$$(sysconfdir)/s|^|#|' ${WRKSRC}/Makefile.in

post-stage:
	@${LN} -f ${STAGEDIR}/${PREFIX}/man/man1/regina.1.gz \
		${STAGEDIR}/${PREFIX}/man/man1/rexx.1.gz

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/regina.pdf ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/regutil.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
