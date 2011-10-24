# New ports collection makefile for:	imp-interpreter
# Date created:		2006-08-15
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	IMP
PORTVERSION=	1.0.7
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	http://www.ocaml.info/ocaml_sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monadic interpreter of a simple imperative language

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/monad
ALL_TARGET=	nc

PLIST_FILES=	bin/IMP

.if !defined(NOPORTDOCS)
PORTDOCS=	README
.endif

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main ${PREFIX}/bin/IMP

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
