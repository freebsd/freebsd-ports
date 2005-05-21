# ex:ts=8
# Ports collection makefile for:	camomile
# Date created:			Mar 17, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	camomile
PORTVERSION=	0.5.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A comprehensive Unicode library for objective caml language

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib

BROKEN=		Changes permissions of installed file

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

PKGDEINSTALL=	${PKGINSTALL}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Need working <wctype.h>"
.endif

post-install:
	@${FIND} ${PREFIX}/lib/ocaml/site-lib/${PORTNAME} -type f | \
		${SED} "s,^${PREFIX}/,," >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm lib/ocaml/site-lib/${PORTNAME}" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec ocamlfind remove ${PORTNAME} 2>/dev/null || true" >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
