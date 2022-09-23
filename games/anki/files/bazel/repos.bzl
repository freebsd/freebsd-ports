# Definitions of local bazel repositories

def register_repos():
    "Register required dependency repos."

    # bazel
    #########
    native.local_repository(
	name = "bazel_skylib",
	path = "%%_MY_LOCALREPO%%/bzlskylib",
    )

    # rust
    ########
    native.local_repository(
	name = "rules_rust",
	path = "%%_MY_LOCALREPO%%/rules_rust",
    )

    # protobuf
    ############
    native.local_repository(
	name = "rules_proto",
	path = "%%_MY_LOCALREPO%%/rules_proto",
    )

    # python
    ##########
    native.local_repository(
	name = "rules_python",
	path = "%%_MY_LOCALREPO%%/rules_python",
    )

    # javascript
    ##############
    native.local_repository(
	name = "build_bazel_rules_nodejs",
	path = "%%_MY_LOCALREPO%%/rules_nodejs",
    )

    native.local_repository(
	name = "rules_nodejs",
	path = "%%_MY_LOCALREPO%%/rules_nodejs",
    )

    # sass
    ########
    native.local_repository(
        name = "io_bazel_rules_sass",
	path = "%%_MY_LOCALREPO%%/rules_sass",
    )

    # i18n translation files
    ##########################
    native.local_repository(
        name = "rslib_ftl",
	path = "%%_MY_LOCALREPO%%/ftlrslib",
    )

    # i18n extra files
    ####################
    native.local_repository(
        name = "extra_ftl",
	path = "%%_MY_LOCALREPO%%/ftlextra",
    )

    # transitive dependency
    #########################
    native.local_repository(
        name = "rules_cc",
	path = "%%_MY_LOCALREPO%%/rules_cc",
    )

    # transitive dependency
    #########################
    native.local_repository(
        name = "rules_java",
	path = "%%_MY_LOCALREPO%%/rules_java",
    )

    # transitive dependency
    #########################
    native.local_repository(
        name = "build_bazel_rules_typescript",
        path = "%%_MY_LOCALREPO%%/rules_nodejs/third_party/github.com/bazelbuild/rules_typescript",
    )

    # provides node from ports
    ############################
    native.local_repository(
        name = "local_node",
	path = "%%_MY_LOCALREPO%%/local_node",
    )
