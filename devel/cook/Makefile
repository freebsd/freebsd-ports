# Created by: jasone
# $FreeBSD$

PORTNAME=	cook
PORTVERSION=	2.30
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	http://miller.emu.id.au/pmiller/software/cook/ \
		LOCAL/jasone

MAINTAINER=	jasone@FreeBSD.org
COMMENT=	Like make(1), but more powerful and clean

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC=yacc
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

USES=		gettext perl5
DESTDIRNAME=	RPM_BUILD_ROOT

# Make sure that the whole directory tree exists.
pre-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/cook/en/man1
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/cook/en/LC_MESSAGES

# cook installs extra copies of the manpages in a directory that MANLANG can't
# cope with.  Delete the extra copies.
post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/share/cook/en/man1

.include <bsd.port.mk>
