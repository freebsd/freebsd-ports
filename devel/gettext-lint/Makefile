# ex:ts=8
# Ports collection makefile for:	gettext-lint
# Date created:			Feb 3, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gettext-lint
PORTVERSION=	0.1.1
CATEGORIES=	devel
MASTER_SITES=	http://mega.ist.utl.pt/~pmmm/gettext-lint/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check the validity and consistency of PO and POT files

RUN_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext

USE_REINPLACE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
MAKE_ENV=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

post-patch:
	@${GREP} -lR "/usr/share/gettext-lint" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e "s,/usr/share/gettext-lint,${PYTHON_SITELIBDIR}/gettext-lint,"

.include <bsd.port.mk>
