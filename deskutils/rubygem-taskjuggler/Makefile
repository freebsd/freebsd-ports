# Created by: Dean Povey <povey@wedgetail.com>
# $FreeBSD$

PORTNAME=	taskjuggler
PORTVERSION=	3.6.0
CATEGORIES=	deskutils rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Project management tool for UNIX based operating systems

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-mail>=2.4.3:mail/rubygem-mail \
		rubygem-term-ansicolor>=1.0.7:devel/rubygem-term-ansicolor

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/tj3 \
		bin/tj3client \
		bin/tj3d \
		bin/tj3man \
		bin/tj3ss_receiver \
		bin/tj3ss_sender \
		bin/tj3ts_receiver \
		bin/tj3ts_sender \
		bin/tj3ts_summary \
		bin/tj3webd

.include <bsd.port.mk>
