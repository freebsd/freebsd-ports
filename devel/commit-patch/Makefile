PORTNAME=	commit-patch
PORTVERSION=	2.6.2
CATEGORIES=	devel

MAINTAINER=	lapo@lapo.it
COMMENT=	Commit patches or partial workspace changes to a VCS repository
WWW=		https://www.porkrind.org/commit-patch/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	interdiff:misc/patchutils \
		p5-IPC-Run>=0:devel/p5-IPC-Run

USE_GITHUB=	yes
USES=		gmake perl5 shebangfix
USE_PERL5=	build # pod2man
SHEBANG_FILES=	commit-patch

GH_ACCOUNT=	caldwell

NO_ARCH=	yes
PLIST_FILES=	bin/commit-partial bin/commit-patch \
		share/emacs/site-lisp/commit-patch-buffer.el \
		share/man/man1/commit-partial.1.gz share/man/man1/commit-patch.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
MAKE_JOBS_UNSAFE=	yes

post-patch:
		${REINPLACE_CMD} -e 's/PREFIX=/PREFIX?=/' \
			-e 's/$$(PREFIX)/$$(DESTDIR)$$(PREFIX)/' \
			${WRKSRC}/Makefile

.include <bsd.port.mk>
