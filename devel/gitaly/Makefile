# $FreeBSD$

PORTNAME=	gitaly
DISTVERSION=	0.91.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	idefix@fechner.net
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# define dependencies that are required for build and run under MY_DEPENDS
MY_DEPENDS=	git>=2.16.2:devel/git \
		rubygem-github-linguist53>=5.3.3:textproc/rubygem-github-linguist53 \
		rubygem-bundler>0:sysutils/rubygem-bundler \
		rubygem-gitlab-markup>=1.6.2:textproc/rubygem-gitlab-markup \
		rubygem-gitaly-proto088>=0.88.0:net/rubygem-gitaly-proto088 \
		rubygem-activesupport50>=5.0.2:devel/rubygem-activesupport50 \
		rubygem-rdoc>=4.2:devel/rubygem-rdoc \
		rubygem-gollum-lib-gitlab>=4.2.0:www/rubygem-gollum-lib-gitlab \
		rubygem-gollum-rugged_adapter>=0.4.4:www/rubygem-gollum-rugged_adapter \
		rubygem-grpc>=1.10.0:net/rubygem-grpc \
		rubygem-sentry-raven>=2.7.2:devel/rubygem-sentry-raven \
		rubygem-licensee8>=8.7:devel/rubygem-licensee8 \
		rubygem-google-protobuf351>=3.5.1:devel/rubygem-google-protobuf351

BUILD_DEPENDS=	go>=1.8:lang/go \
		gem:devel/ruby-gems \
		${MY_DEPENDS}

RUN_DEPENDS=	${MY_DEPENDS} \
		gitlab-shell>=6.0.4:devel/gitlab-shell

USES=		gmake
USE_RUBY=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find this here: https://gitlab.com/gitlab-org/gitaly/tags
GL_COMMIT=	89298fe8b80b73a34352023555fe061866aff3ad

post-patch:
	${MV} ${WRKSRC}/config.toml.example ${WRKSRC}/config.toml.sample

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	$(RM) -f ${WRKSRC}/ruby/Gemfile.orig
	(cd ${WRKSRC}/_build/bin/ && ${COPYTREE_SHARE} .  ${STAGEDIR}${DATADIR}/bin && \
	cd ${WRKSRC} && ${COPYTREE_SHARE} config.toml.sample  ${STAGEDIR}${DATADIR}) && \
	cd ${WRKSRC}/ruby && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/ruby

post-install:
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/bin/gitaly
	${STRIP_CMD} ${STAGEDIR}${DATADIR}/bin/gitaly-ssh

.include <bsd.port.mk>
