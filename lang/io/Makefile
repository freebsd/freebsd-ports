# New ports collection makefile for:	io
# Date created:		4 Nov 2005
# Whom:			Hye-Shik Chang
#
# $FreeBSD$
#

PORTNAME=	io
PORTVERSION=	0.0.2009.08.03
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL} \
    		http://people.freebsd.org/~gahr/distfiles/
DISTNAME=	io-${PORTVERSION:S/0.0.//}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Small prototype-based programming language

USE_GMAKE=	yes
CFLAGS+=	-fPIC
USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${DISTNAME}
MAKE_ENV=	INSTALL_PREFIX="${PREFIX}"

# All addons that do not require extra dependencies
# Additional addons may be added as separate ports with some
# makefile hacking in a manner similar to Qt4 ports
DEFAULT_ADDONS=	AsyncRequest Blowfish Box CGI ContinuedFraction Curses \
		EditLine Flux Fnmatch LZO Loki MD5 NetworkAdapter \
		NotificationCenter Random Range Rational ReadLine SHA1 \
		SqlDatabase Syslog SystemCall Thread User Zlib

PORTDOCS=	*
PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

post-patch:
	@cd ${WRKSRC}/addons && for addon in *; do \
		if ! ${ECHO_CMD} ${DEFAULT_ADDONS} | ${GREP} $$addon > /dev/null; then \
			${RM} -fr $$addon; \
		fi; \
	done

	@${REINPLACE_CMD} -e 's|CFLAGS = $$(OPTIMIZE)|CFLAGS +=|' \
		${WRKSRC}/Makefile.lib
	@${REINPLACE_CMD} -e '/CC = gcc/ d' \
		${WRKSRC}/libs/basekit/source/simd_cph/test/Makefile
	@${REINPLACE_CMD} -e '/cp _build\/dll\/.*\/bin/ d' ${WRKSRC}/Makefile
.if ${ARCH} == "amd64"
	@${REINPLACE_CMD} -e 's|^CFLAGS =|CFLAGS = -fPIC|' \
	    ${WRKSRC}/Makefile.lib \
	    ${WRKSRC}/libs/basekit/Makefile.lib
.endif

post-install:
	${MKDIR} ${PREFIX}/include/io
	${INSTALL_DATA} ${WRKSRC}/_build/headers/* ${PREFIX}/include/io

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	@cd ${WRKSRC}/samples && ${COPYTREE_SHARE} . ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
