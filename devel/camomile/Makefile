# ex:ts=8
# Ports collection makefile for:	camomile
# Date created:			Mar 17, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	camomile
PORTVERSION=	0.4.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A comprehensive Unicode library for objective caml language

BUILD_DEPENDS=	ocamlc:${PORTSDIR}/lang/ocaml \
		ocamlfind:${PORTSDIR}/devel/ocaml-findlib

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-install:
	@${ECHO_CMD} "@unexec ocamlfind remove camomile 2>/dev/null || true" >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
