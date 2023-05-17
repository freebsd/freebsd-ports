PORTNAME=	skyeye
PORTVERSION=	1.2.5
DISTVERSIONSUFFIX=	_REL
PORTREVISION=	8
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Environment simulates typical ARM-base embedded computer systems
WWW=		http://www.skyeye.org/

LICENSE=	GPLv2

DEPRECATED=	Upstream last release was in 2014
EXPIRATION_DATE=	2023-06-17
BROKEN=		error: too many arguments to function 'bfd_section_size'

USE_BINUTILS=	yes
USE_CSTD=	gnu89
USE_GCC=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_func_working_mktime=yes

CFLAGS+=	-fcommon

PLIST_FILES=	bin/skyeye

.include <bsd.port.mk>
