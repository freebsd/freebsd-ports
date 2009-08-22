# New ports collection makefile for:	A-A-P GUI IDE: agide
# Date created:				26 August 2003
# Whom:					Rui Lopes <rui@ruilopes.com>
#
# $FreeBSD$
#

PORTNAME=	agide
PORTVERSION=	0.124
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/a-a-p/Agide/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A-A-P GUI IDE: a framework for software development

RUN_DEPENDS=	${LOCALBASE}/bin/aap:${PORTSDIR}/devel/aap \
		${LOCALBASE}/bin/vim:${PORTSDIR}/editors/vim

BROKEN=		does not build

MAN1=		agide.1

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_ZIP=	yes
USE_PYTHON=	yes
USE_WX=		2.4
WX_COMPS=	python
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
IGNORE=		triggers python crash on startup. 
.endif

post-patch:
	${REINPLACE_CMD} -e "s,share/man,man," ${WRKSRC}/main.aap

pre-install:
	@${SH} ${FILESDIR}/check_vim

do-install:
	@cd ${WRKSRC} && \
		${PREFIX}/bin/aap PREFIX="${PREFIX}" install

.include <bsd.port.post.mk>
