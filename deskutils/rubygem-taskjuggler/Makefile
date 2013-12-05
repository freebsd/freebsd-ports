# Created by: Dean Povey <povey@wedgetail.com>
# $FreeBSD$

PORTNAME=	taskjuggler
PORTVERSION=	3.5.0
CATEGORIES=	deskutils rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Project management tool for UNIX based operating systems

LICENSE=	GPLv2

RUN_DEPENDS=	rubygem-mail>=2.4.3:${PORTSDIR}/mail/rubygem-mail \
		rubygem-term-ansicolor>=1.0.7:${PORTSDIR}/devel/rubygem-term-ansicolor

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

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
