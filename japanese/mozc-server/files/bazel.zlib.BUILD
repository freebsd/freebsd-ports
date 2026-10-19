load("@rules_cc//cc:cc_library.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

cc_library(
    name = "z",
    linkopts = ["/usr/lib/libz.so"],
)

alias(
    name = "zlib",
    actual = ":z",
)
