# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	id3lib
PORTVERSION=	3.8.3
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for manipulating ID3v1/v1.1 and ID3v2 tags

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_mips=	fails to link: '_ZTSN12_GLOBAL__N_117ConstIteratorImplE' referenced in section '.data.rel.ro' of tag.lo: defined in discarded section
BROKEN_mips64=	fails to link: '_ZTSN12_GLOBAL__N_117ConstIteratorImplE' referenced in section '.data.rel.ro' of tag.lo: defined in discarded section

USES=		compiler:c11 iconv libtool localbase

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-extract:
	@${RM} -r ${WRKSRC}/zlib

.include <bsd.port.mk>
