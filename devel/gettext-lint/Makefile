# ex:ts=8
# Ports collection makefile for:	gettext-lint
# Date created:			Feb 3, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gettext-lint
PORTVERSION=	0.3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=gettext-lint

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Check the validity and consistency of PO and POT files

RUN_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext

USE_REINPLACE=	yes
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
MAKE_ENV=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR}

MAN1=		POFileConsistency.1 POFileChecker.1 POFileSpell.1 POFileFill.1 \
		POFileEquiv.1 POFileStatus.1

post-patch:
	@${GREP} -lR "@prefix@/share/@PACKAGE@" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e "s,@prefix@/share/@PACKAGE@,${PYTHON_SITELIBDIR}/@PACKAGE@,"

.include <bsd.port.mk>
