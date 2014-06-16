# Created by: Yonatan <onatan@gmail.com>
# $FreeBSD$

PORTNAME=	hspell
PORTVERSION=	1.1
CATEGORIES=	hebrew
MASTER_SITES=	http://hspell.ivrix.org.il/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	makc

MAINTAINER=	onatan@gmail.com
COMMENT=	Hebrew spellchecker and morphology engine

USES=		shebangfix gmake perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes
CFLAGS+=	-fPIC
SHEBANG_FILES=	pmerge multispell

SUB_FILES=	pkg-message
SUB_LIST=	PORTSDIR=${PORTSDIR}

.include <bsd.port.mk>
