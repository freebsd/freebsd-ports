# New ports collection makefile for:	ocaml-examples
# Date created:		2006-07-27
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	ocaml
PORTVERSION=	3.11
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=   http://cristal.inria.fr/caml_examples/
PKGNAMESUFFIX=	-examples
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Example programs for the Objective Caml

NO_BUILD=	yes

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	@${TAR} -cf- -C ${WRKSRC} --exclude Imakefile . | \
		${TAR} -xf- -C ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;
	@${FIND} ${EXAMPLESDIR} -exec ${CHOWN} ${SHAREOWN} {} \;

.include <bsd.port.mk>
