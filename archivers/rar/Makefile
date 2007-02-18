# New ports collection makefile for:    rar
# Date created:         15 May 1996
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	rar
PORTVERSION=	3.70b1
PORTEPOCH=	1
CATEGORIES=	archivers
MASTER_SITES=	http://files.rarlab.com/rar/ \
		http://files2.rarlab.com/rar/
DISTNAME=	rarbsd-3.7.b1

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	File archiver (binary port)

IA32_BINARY_PORT=	YES
RESTRICTED=	only unmodified original package can be distributed
NO_BUILD=	yes
STRIP=
WRKSRC=		${WRKDIR}/rar
PLIST_FILES=	bin/rar lib/default.sfx etc/rarfiles.lst man/cat1/rar.1
PORTDOCS=	technote.txt license.txt whatsnew.txt order.htm \
		readme.txt file_id.diz

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 503000
IGNORE=	is unsupported on versions prior to FreeBSD 5.3
.endif

.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
.endif

do-install:
.if !defined(WITH_STATIC)
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${PREFIX}/bin/rar
.else
	${INSTALL_PROGRAM} ${WRKSRC}/rar_static ${PREFIX}/bin/rar
.endif
	${INSTALL_MAN} ${WRKSRC}/rar.txt ${PREFIX}/man/cat1/rar.1
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${PREFIX}/lib

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
