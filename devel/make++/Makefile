# ex:ts=8
# New ports collection makefile for:	make++
# Date created:			Fab 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	make++
PORTVERSION=	1.10
CATEGORIES=	devel
MASTER_SITES=	http://lnc.usc.edu/~holt/makepp/
DISTNAME=	${PORTNAME:S/+/p/g}-${PORTVERSION}

MAINTAINER=	ijliao@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5

USE_PERL5=	yes

do-build:
	@${PERL} -pi -e "s|\@htmldir\@|${PREFIX}/share/makepp/html|g ; \
		s|\@datadir\@|${PREFIX}/share/makepp|g" ${WRKSRC}/makepp

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/makepp ${PREFIX}/bin

	@${MKDIR} ${PREFIX}/share/makepp
	@${MKDIR} ${PREFIX}/share/makepp/Signature

	${INSTALL_SCRIPT} ${WRKSRC}/recursive_makepp ${PREFIX}/share/makepp

.for module in FileInfo FileInfo_makepp MakeEvent Glob Makefile Makesubs Rule Signature TextSubs Signature/exact_match Signature/target_newer Signature/c_compilation_md5 Signature/md5
	${INSTALL_SCRIPT} ${WRKSRC}/${module}.pm ${PREFIX}/share/makepp/${module}.pm
.endfor

.for include in c_compilation_md5 infer_objects makepp_builtin_rules makepp_default_makefile
	${INSTALL_DATA} ${WRKSRC}/${include}.mk ${PREFIX}/share/makepp
.endfor

	@${MKDIR} ${PREFIX}/share/makepp/html
	${CP} ${WRKSRC}/doc/*.html ${PREFIX}/share/makepp/html

.include <bsd.port.mk>
