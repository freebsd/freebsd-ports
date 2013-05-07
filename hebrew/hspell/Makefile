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

USES=		shebangfix
USE_PERL5_BUILD=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	-fPIC
SHEBANG_FILES=	pmerge

MAN1=		hspell.1
MAN3=		hspell.3
SUB_FILES=	pkg-message
SUB_LIST=	PORTSDIR=${PORTSDIR}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
