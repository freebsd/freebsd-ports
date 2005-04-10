# New ports collection makefile for:	ZThread
# Date created:				23 May 2001
# Whom:					pvh@egenetics.com
#
# $FreeBSD$
#

PORTNAME=	zthread
PORTVERSION=	2.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	ZThread-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A platform-independent object-oriented C++ threading library

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-ftime
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.3
.endif

post-extract:
	@${FIND} ${WRKSRC} -name CVS -type d -delete

post-install:
	@${FIND} ${PREFIX}/include/zthread -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm include/zthread" >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
.for docfile in AUTHORS ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
	${CP} -R ${WRKSRC}/doc/html/ ${DOCSDIR}/html
.endif

.include <bsd.port.post.mk>
