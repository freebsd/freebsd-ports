# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	ocaml
PORTVERSION=	3.12
CATEGORIES=	lang
MASTER_SITES=	http://cristal.inria.fr/caml_examples/
PKGNAMESUFFIX=	-examples
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Example programs for the Objective Caml

DEPRECATED=	Outdated and discontinued; new examples are in lang/ocaml
EXPIRATION_DATE=2014-06-01

NO_BUILD=	yes

do-install:
.ifndef		NOPORTEXAMPLES
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${TAR} -cf- -C ${WRKSRC} --exclude Imakefile . | \
		${TAR} -xf- -C ${STAGEDIR}${EXAMPLESDIR}
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${FIND} ${STAGEDIR}${EXAMPLESDIR} -exec ${CHOWN} ${SHAREOWN} {} \;
.endif

.include <bsd.port.mk>
