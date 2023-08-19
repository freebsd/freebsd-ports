PORTNAME=	cook
PORTVERSION=	2.30
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://miller.emu.id.au/pmiller/software/cook/ \
		LOCAL/jasone

MAINTAINER=	jasone@FreeBSD.org
COMMENT=	Like make(1), but more powerful and clean
WWW=		http://miller.emu.id.au/pmiller/software/cook/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=	fails to build: a space character is not allowed in an escape sequence parameter
DEPRECATED=	Upstream last release was in 2008
EXPIRATION_DATE=	2023-12-31

USES=		gettext groff localbase:ldflags perl5

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC=yacc

DESTDIRNAME=	RPM_BUILD_ROOT
MAKE_JOBS_UNSAFE=	yes

# Make sure that the whole directory tree exists.
pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cook/en/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cook/en/LC_MESSAGES

# cook installs extra copies of the manpages in a directory that MANLANG can't
# cope with.  Delete the extra copies.
post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/cook/en/man1

.include <bsd.port.mk>
