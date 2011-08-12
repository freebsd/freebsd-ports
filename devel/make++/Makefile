# ex:ts=8
# New ports collection makefile for:	make++
# Date created:			Fab 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	make++
DISTVERSION=	1.40.1a
CATEGORIES=	devel perl5
MASTER_SITES=	SF/${PORTNAME:S/+/p/g}/${DISTVERSION:S/a//}
DISTNAME=	${PORTNAME:S/+/p/g}-${DISTVERSION:S/\.a//}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A drop-in replacement for GNU make

LICENSE=	ART10 GPLv1 GPLv2 GPLv3
LICENSE_COMB=	dual

WRKSRC=		${WRKDIR}/${PORTNAME:S/+/p/g}-${DISTVERSION:R}

USE_PERL5=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --mandir=${MANPREFIX}/man

DATADIR=	${PREFIX}/share/${PORTNAME:S/+/p/g}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME:S/+/p/g}

MAN1=		makepp.1 makepp_build_algorithm.1 \
		makepp_builtin.1 makepp_command.1 \
		makepp_cookbook.1 makepp_extending.1 \
		makepp_functions.1 makepp_incompatibilities.1 \
		makepp_release_notes.1 makepp_repositories.1 \
		makepp_rules.1 makepp_scanning.1 \
		makepp_signatures.1 makepp_statements.1 \
		makepp_tutorial.1 makepp_tutorial_compilation.1 \
		makepp_variables.1 makeppclient.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500703
RUN_DEPENDS+=	p5-Digest-MD5>=2.16:${PORTSDIR}/security/p5-Digest-MD5
.endif

.if defined(NOPORTDOCS)
CONFIGURE_ARGS+=--htmldir=none
.else
CONFIGURE_ARGS+=--htmldir=${DOCSDIR}/html
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^all:/s|test||' ${WRKSRC}/config.pl

.include <bsd.port.post.mk>
