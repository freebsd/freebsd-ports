# ex:ts=8
# New ports collection makefile for:	make++
# Date created:			Fab 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	make++
PORTVERSION=	2.0
CATEGORIES=	devel perl5
MASTER_SITES=	SF/${PORTNAME:S/+/p/g}/${PORTVERSION}
DISTNAME=	${PORTNAME:S/+/p/g}-${PORTVERSION}
EXTRACT_SUFX=	.txz

MAINTAINER=	gavin@16degrees.com.au
COMMENT=	A drop-in replacement for GNU make

LICENSE=	ART10 GPLv1 GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		perl5
USE_XZ=		yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man

DATADIR=	${PREFIX}/share/${PORTNAME:S/+/p/g}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/+/p/g}

MAN1=		makepp.1 makepp_build_algorithm.1 \
		makepp_build_cache.1 makepp_build_check.1 \
		makepp_builtin.1 makepp_builtins.1 \
		makepp_command.1 makepp_compatibility.1 \
		makepp_cookbook.1 makepp_extending.1 \
		makepp_faq.1 makepp_functions.1 \
		makepp_incompatibilities.1 makepp_release_notes.1 \
		makepp_repositories.1 makepp_rules.1 \
		makepp_sandboxes.1 makepp_scanning.1 \
		makepp_signatures.1 makepp_speedup.1 \
		makepp_statements.1 makepp_tutorial.1 \
		makepp_tutorial_compilation.1 makepp_variables.1 \
		makeppbuiltin.1 makeppclean.1 \
		makeppgraph.1 makeppinfo.1 \
		makepplog.1 makeppreplay.1 \
		perl_performance.1

.include <bsd.port.pre.mk>

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=--htmldir=none
.else
CONFIGURE_ARGS+=--htmldir=${DOCSDIR}/html
.endif

post-patch:
	@${TOUCH} ${WRKSRC}/.test_done

.include <bsd.port.post.mk>
