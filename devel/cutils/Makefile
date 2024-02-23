PORTNAME=	cutils
PORTVERSION=	1.6
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://www.sigala.it/sandro/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Miscellaneous C programmer's utilities
WWW=		http://www.sigala.it/sandro/software.php #cutils

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share

MAKE_JOBS_UNSAFE=	yes

CONFLICTS=	cdecl

OPTIONS_DEFINE=	INFO
OPTIONS_DEFAULT=	INFO

INFO_USES=		makeinfo
INFO_MAKE_ENV=	MAKEINFO="${MAKEINFO}"
INFO_INFO=		cutils

post-patch-INFO-off:
	@${REINPLACE_CMD} -e '/^subdirs/s|doc||g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
