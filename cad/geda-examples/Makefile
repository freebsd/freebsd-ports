# New ports collection makefile for:	geda
# Date created:			27 June 2006
# Whom:				Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	examples
PORTVERSION=	20070216
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PORTVERSION}/ \
		http://geda.seul.org/devel/${PORTVERSION}/
PKGNAMEPREFIX=	geda-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	The gEDA's examples

NO_BUILD=	yes

EXAMPLESDIR=	${PREFIX}/share/examples/geda

.include <bsd.port.pre.mk>

EXAMPLES!=	${CAT} ${FILESDIR}/examples

do-install:
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC} \
	 && ${FIND} -d ${EXAMPLES} -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \; \
	 && ${FIND} -d ${EXAMPLES} -type f -exec ${INSTALL_DATA} {} \
	 ${EXAMPLESDIR}/{} \;)

.include <bsd.port.post.mk>
